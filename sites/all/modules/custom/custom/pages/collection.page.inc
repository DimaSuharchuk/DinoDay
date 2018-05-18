<?php
/**
 * @file
 * Collection page logic and view.
 */

/**
 * Collection page.
 */
function custom_collection_page() {
  global $user;

  if (!$user->uid) {
    custom_ctools_popup_style();
  }

  $page = [];

  $page['collection'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['dinosaurs-table', 'columns', 'medium-6'],
    ],
  ];
  $page['collection']['dinosaurs'] = drupal_get_form('custom_collection_form');

  $page['dino_info_wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['dinosaurs-info-block', 'columns', 'medium-6'],
    ],
  ];
  $page['dino_info_wrapper']['dino_info'] = [
    '#type' => 'container',
    '#attributes' => [
      'id' => 'dinosaur-info',
    ],
  ];

  return $page;
}

/**
 * Form with dinosaurs pictures as buttons.
 */
function custom_collection_form($form, &$from_state) {
  global $user;

  $user_dinosaurs = [];

  if ($user->uid) {
    $user_dinosaurs = $user->dinosaurs ? unserialize($user->dinosaurs) : [];
  }

  $pictures_path = db_select('eck_dinosaur', 'd')
    ->fields('d', ['picture'])
    ->execute()
    ->fetchCol();

  $options = [];
  // Iterator to accordance with dinosaurs ids in DB.
  $i = 1;
  foreach ($pictures_path as $value) {
    // Add class to dinosaurs.
    $rank_style = 'no-rank';

    if (!in_array($i, array_keys($user_dinosaurs))) {
      $value = _get_dinosaur_black_picture_path($value);
    }
    else {
      $rank_style = _get_dinosaur_style_by_id($i);
    }

    $options[$i++] = "<img src='{$value}' data-rank='{$rank_style}'/>";
  }

  $form['dinosaurs'] = [
    '#type' => 'radios',
    '#options' => $options,
  ];
  // Not need to show anonymous users any dinosaurs info.
  if ($user->uid) {
    $form['dinosaurs']['#ajax'] = [
      'callback' => 'custom_dinosaur_info_ajax_callback',
      'wrapper' => 'dinosaur-info',
      'progress' => FALSE,
    ];
  }

  return $form;
}

/**
 * Render chosen dinosaur info.
 *
 * @param $form
 * @param $form_state
 *
 * @return string
 * @throws \Exception
 */
function custom_dinosaur_info_ajax_callback($form, $form_state) {
  global $user;

  $user_dinosaurs = $user->dinosaurs ? unserialize($user->dinosaurs) : [];

  $dino_id = $form_state['values']['dinosaurs'];
  $dino_entity = entity_load_single('dinosaur', $dino_id);

  if (in_array($dino_id, array_keys($user_dinosaurs))) {
    return theme('dinosaur_info', [
      'dinosaur_entity' => $dino_entity,
    ]);
  }
  else {
    return theme('dinosaur_undefined_info', [
      'dinosaur_entity' => $dino_entity,
    ]);
  }
}

/**
 * Helper function converts dinosaur's picture path to dinosaur's black picture
 * path.
 *
 * @param $path
 *  Path to image.
 *
 * @return string
 *  Path to black image.
 */
function _get_dinosaur_black_picture_path($path) {
  list($v1, $v2) = explode('.', $path);
  return "$v1-black.$v2";
}

/**
 * Helper function returns css class for dinosaur rank.
 *
 * @param $id
 *  Dinosaur's ID from DB.
 *
 * @return string
 *  Class name.
 */
function _get_dinosaur_style_by_id($id) {
  switch (TRUE) {
    case ($id > 0 && $id <= 15):
      return 'rank-1';
      break;

    case ($id >= 16 && $id <= 25):
      return 'rank-2';
      break;

    case ($id >= 26 && $id <= 29):
      return 'rank-3';
      break;

    case ($id == 30):
      return 'rank-4';
      break;
  }

  return '';
}

/**
 * Helper function returns rounded time.
 *
 * @param $seconds
 *
 * @return string
 */
function _get_past_time($seconds) {
  switch (TRUE) {
    case ($seconds < 60):
      return format_plural($seconds, '1 second', '@count seconds');
      break;

    case ($seconds < 3600):
      return format_plural(floor($seconds / 60), '1 minute', '@count minutes');
      break;

    case ($seconds < 86400):
      return format_plural(floor($seconds / 3600), '1 hour', '@count hours');
      break;

    case ($seconds >= 86400):
      return format_plural(floor($seconds / 86400), '1 day', '@count days');
      break;
  }

  return '';
}
