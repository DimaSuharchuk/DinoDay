<?php
/**
 * @file
 * Collection page logic and view.
 */

/**
 * Collection page.
 */
function custom_collection_page() {
  $page = [];

  $page['collection'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['dinosaurs-table', 'columns', 'medium-6'],
    ],
  ];
  $page['collection']['dinosaurs'] = drupal_get_form('custom_collection_form');

  $page['dino_info'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['dinosaur-info', 'columns', 'medium-6'],
      'id' => 'dinosaur-info',
    ],
  ];

  return $page;
}

/**
 * Form with dinosaurs pictures as buttons.
 */
function custom_collection_form($form, &$from_state) {
  $pictures_path = db_select('eck_dinosaur', 'd')
    ->fields('d', ['picture'])
    ->execute()
    ->fetchCol();

  $options = [];
  foreach ($pictures_path as $value) {
    // @todo Display as black pictures.
    /**
     * list($v1, $v2) = explode('.', $value);
     * $value = "$v1-black.$v2";
     **/
    $options[] = "<img src='{$value}'/>";
  }

  $form['dinosaurs'] = [
    '#type' => 'radios',
    '#options' => $options,
    // @todo Add black disabled options for non-opened dinosaurs.
    // @todo Add ajax callback with display dinosaur info in #dinosaur-info.
  ];

  return $form;
}
