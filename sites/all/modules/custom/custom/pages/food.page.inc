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

  $options_food = $options_beat_1 = $options_beat_2 = $options_beat_3 = $options_beat_4 = [];
  foreach ($user_food_ids as $i => $id) {
    if (key_exists($id, $food_entities)) {
      $food_picture = "<img src='{$food_entities[$id]->picture}' />";
      switch ($id) {
        case '17':
          $options_beat_1[$i] = $food_picture;
          break;
        case '18':
          $options_beat_2[$i] = $food_picture;
          break;
        case '19':
          $options_beat_3[$i] = $food_picture;
          break;
        case '20':
          $options_beat_4[$i] = $food_picture;
          break;
        default:
          $options_food[$i] = $food_picture;
      }
    }
  }

  // Display items by range in fieldsets.
  $set_schema = [
    'food' => [
      'title' => 'Ингредиенты',
      'options' => $options_food,
      'classes' => ['food'],
      'message_if_null' => 'Ингредиентов пока нет, нажмите кнопку вверху экрана для получения ингредиента.',
    ],
    'beat_1' => [
      'title' => 'Наживки ур. I',
      'options' => $options_beat_1,
      'classes' => ['beat-1'],
      'message_if_null' => 'Наживок первого уровня пока нет. Выделите 3 любых ингредиента и нажмите кнопку "Приготовить".',
    ],
    'beat_2' => [
      'title' => 'Наживки ур. II',
      'options' => $options_beat_2,
      'classes' => ['beat-2'],
      'message_if_null' => 'Наживок второго уровня пока нет. Выделите 3 любых наживки первого уровня и нажмите кнопку "Приготовить".',
    ],
    'beat_3' => [
      'title' => 'Наживки ур. III',
      'options' => $options_beat_3,
      'classes' => ['beat-3'],
      'message_if_null' => 'Наживок третьего уровня пока нет. Выделите 3 любых наживки второго уровня и нажмите кнопку "Приготовить".',
    ],
    'beat_4' => [
      'title' => 'Наживки ур. IV',
      'options' => $options_beat_4,
      'classes' => ['beat-4'],
      'message_if_null' => 'Наживок четвертого уровня пока нет. Выделите 3 любых наживки третьего уровня и нажмите кнопку "Приготовить".',
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
    '#type' => 'image_button',
    '#src' => FOOD_PICTURE_DIR . '/other/stew-1.svg',
    '#ajax' => [
      'callback' => 'custom_food_ajax_callback',
      'wrapper' => 'user-food-block',
      'method' => 'replace',
      'effect' => 'fade',
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

    case 'beat_1':
      array_push($user_food, 18);
      break;

    case 'beat_2':
      array_push($user_food, 19);
      break;

    case 'beat_3':
      array_push($user_food, 20);
      break;
  }
  $user->food = implode(',', $user_food);

  user_save($user);

  // Reload page.
  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  $commands = [];
  $commands[] = ctools_ajax_command_reload();
  print ajax_render($commands);
  drupal_exit();
}
