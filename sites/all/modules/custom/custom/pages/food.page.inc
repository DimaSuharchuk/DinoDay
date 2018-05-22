<?php
/**
 * @file
 * Food page logic and view.
 */

/**
 * Food page form.
 */
function custom_food_form($form, &$form_state) {
  global $user;

  $form['food_set'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['user-food-block', 'columns', 'medium-6'],
      'id' => 'user-food-block',
    ],
    '#tree' => TRUE,
  ];

  $user_food_ids = explode(',', $user->food);
  $food_entities = entity_load('food', $user_food_ids);

  $options_food = $options_bait_1 = $options_bait_2 = $options_bait_3 = $options_bait_4 = [];
  foreach ($user_food_ids as $i => $id) {
    if (key_exists($id, $food_entities)) {
      $food_picture = "<img src='{$food_entities[$id]->picture}' />";
      switch ($id) {
        case '17':
          $options_bait_1[$i] = $food_picture;
          break;
        case '18':
          $options_bait_2[$i] = $food_picture;
          break;
        case '19':
          $options_bait_3[$i] = $food_picture;
          break;
        case '20':
          $options_bait_4[$i] = $food_picture;
          break;
        default:
          $options_food[$i] = $food_picture;
      }
    }
  }

  // Display items by range in fieldsets.
  $set_schema = [
    'food' => [
      'title' => t('Ingredients'),
      'options' => $options_food,
      'classes' => ['food'],
      'message_if_null' => t('There are no ingredients yet, press the button at the top of the screen to get the ingredient.'),
    ],
    'bait_1' => [
      'title' => t('Bait Level 1'),
      'options' => $options_bait_1,
      'classes' => ['bait', 'bait-1'],
      'message_if_null' => t('Baits of level 1 is not yet there. Select three any ingredients and click the Cook button.'),
    ],
    'bait_2' => [
      'title' => t('Bait Level 2'),
      'options' => $options_bait_2,
      'classes' => ['bait', 'bait-2'],
      'message_if_null' => t('Baits of level 2 is not yet there. Select three any baits of level 1 and click the "Cook" button.'),
    ],
    'bait_3' => [
      'title' => t('Bait Level 3'),
      'options' => $options_bait_3,
      'classes' => ['bait', 'bait-3'],
      'message_if_null' => t('Baits of level 3 is not yet there. Select three any baits of level 2 and click the "Cook" button.'),
    ],
    'bait_4' => [
      'title' => t('Bait Level 4'),
      'options' => $options_bait_4,
      'classes' => ['bait', 'bait-4'],
      'message_if_null' => t('Baits of level 4 is not yet there. Select three any baits of level 3 and click the "Cook" button.'),
    ],
  ];
  foreach ($set_schema as $type => $item) {
    $form['food_set'][$type] = [
      '#type' => 'fieldset',
      '#title' => $item['title'],
      '#collapsible' => TRUE,
      '#collapsed' => !$item['options'],
      '#attributes' => [
        'class' => $item['classes'],
      ],
    ];
    if (!$item['options']) {
      $form['food_set'][$type]['items'] = [
        '#markup' => $item['message_if_null'],
      ];
    }
    else {
      $form['food_set'][$type]['items'] = [
        '#type' => 'checkboxes',
        '#options' => $item['options'],
      ];
    }
  }

  // Block with button for cooking.
  $form['cook_block'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['cook-block', 'columns', 'medium-6'],
      'id' => 'cook-block',
    ],
  ];
  $form['cook_block']['container'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['cook-wrapper'],
    ],
  ];

  // Submit.
  $form['cook_block']['container']['cook'] = [
    '#type' => 'button',
    '#value' => t('Cook a bait'),
    '#ajax' => [
      'callback' => 'custom_food_ajax_callback',
      'effect' => 'fade',
      'progress' => FALSE,
    ],
    '#attributes' => [
      'class' => ['cook-bait-button'],
    ],
  ];
  // Image used as button.
  $form['cook_block']['container']['cook_image'] = [
    '#markup' => theme('image', [
      'path' => FOOD_PICTURE_DIR . '/other/stew-1.svg',
    ]),
  ];

  // Set a bait.
  $form['set_bait'] = [
    '#type' => 'button',
    '#value' => t('Set the bait') . '?',
    '#attributes' => [
      'class' => ['set-bait', 'secondary'],
    ],
    '#states' => [
      'invisible' => [
        '.bait :input' => ['checked' => FALSE],
      ],
    ],
    '#ajax' => [
      'callback' => 'custom_set_bait_ajax_callback',
      'effect' => 'fade',
      'progress' => FALSE,
    ],
  ];

  return $form;
}

/**
 * Food form ajax submit.
 *
 * @param $form
 * @param $form_state
 *
 * @return array
 * @throws \Exception
 */
function custom_food_ajax_callback($form, &$form_state) {
  global $user;

  // Fetch selected by user food ID's.
  $food_sets = $form_state['values']['food_set'];

  // Check what type of food or bait user crafts.
  $food_type = '';
  $selected_food = [];
  foreach ($food_sets as $type => $set) {
    if (count(array_filter($set['items']))) {
      $selected_food = $set['items'];
      $food_type = $type;
      break;
    }
  }
  // Filter from unnecessary values.
  $selected_food = array_filter($selected_food, function ($v, $_) {
    return is_string($v);
  }, ARRAY_FILTER_USE_BOTH);

  $user_food = explode(',', $user->food);
  // Remove used food from DB.
  foreach ($selected_food as $value) {
    unset($user_food[$value]);
  }
  // Add bait.
  switch ($food_type) {
    case 'food':
      array_push($user_food, 17);
      break;

    case 'bait_1':
      array_push($user_food, 18);
      break;

    case 'bait_2':
      array_push($user_food, 19);
      break;

    case 'bait_3':
      array_push($user_food, 20);
      break;
  }
  $user->food = implode(',', $user_food);

  user_save($user);

  $custom_food_form = drupal_get_form('custom_food_form');
  $commands = [];
  $commands[] = ajax_command_replace('#custom-food-form', '<div id="custom-food-form">' . drupal_render($custom_food_form) . '</div>');

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Button set bait to catch.
 *
 * @param $form
 * @param $form_state
 *
 * @return array
 * @throws \Exception
 */
function custom_set_bait_ajax_callback($form, &$form_state) {
  global $user;

  // Fetch selected by user food ID's.
  $food_sets = $form_state['values']['food_set'];

  // Check what type of food or bait user crafts.
  $selected_food = [];
  foreach ($food_sets as $type => $set) {
    if (count(array_filter($set['items']))) {
      $selected_food = $set['items'];
      break;
    }
  }
  // Filter from unnecessary values.
  $selected_food = array_filter($selected_food, function ($v, $_) {
    return is_string($v);
  }, ARRAY_FILTER_USE_BOTH);

  $user_food = explode(',', $user->food);
  // Remove used food from DB.
  foreach ($selected_food as $value) {
    $user->catch = $user_food[$value];
    unset($user_food[$value]);
  }
  $user->food = implode(',', $user_food);

  user_save($user);

  $custom_catch_form = drupal_get_form('custom_catch_form');
  $custom_food_form = drupal_get_form('custom_food_form');
  $commands = [];
  $commands[] = ajax_command_replace('#custom-catch-form', '<div id="custom-catch-form">' . drupal_render($custom_catch_form) . '</div>');
  $commands[] = ajax_command_replace('#custom-food-form', '<div id="custom-food-form">' . drupal_render($custom_food_form) . '</div>');

  return ['#type' => 'ajax', '#commands' => $commands];
}
