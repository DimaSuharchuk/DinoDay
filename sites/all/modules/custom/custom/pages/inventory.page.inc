<?php

/**
 * @file
 * Inventory page logic and view.
 */

/**
 * Inventory page form.
 *
 * {@inheritdoc}
 * @throws \Exception
 */
function custom_inventory_form($form, &$form_state) {
  global $user;

  $form['inventory_set'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['user-inventory-block', 'columns', 'medium-6'],
      'id' => 'user-inventory-block',
    ],
    '#tree' => TRUE,
  ];

  $user_consumables_ids = explode(',', $user->consumables);
  $consumables_entities = entity_load('consumables', $user_consumables_ids);

  $options_consumables = $options_bait_1 = $options_bait_2 = $options_bait_3 = $options_bait_4 = [];
  foreach ($user_consumables_ids as $i => $id) {
    if (key_exists($id, $consumables_entities)) {
      $consumable_picture = "<img src='{$consumables_entities[$id]->picture}' alt=''/>";
      switch ($id) {
        case '17':
          $options_bait_1[$i] = $consumable_picture;
          break;
        case '18':
          $options_bait_2[$i] = $consumable_picture;
          break;
        case '19':
          $options_bait_3[$i] = $consumable_picture;
          break;
        case '20':
          $options_bait_4[$i] = $consumable_picture;
          break;
        default:
          $options_consumables[$i] = $consumable_picture;
      }
    }
  }

  // Display items by range in fieldsets.
  $set_schema = [
    'food' => [
      'title' => t('Ingredients'),
      'options' => $options_consumables,
      'classes' => ['food'],
      'message_if_null' => t('There are no ingredients yet, press the button at the top of the screen to get the ingredient.'),
    ],
    'bait_1' => [
      'title' => t('Bait Level 1'),
      'options' => $options_bait_1,
      'classes' => ['bait', 'bait-1'],
      'message_if_null' => t('Baits of level 1 is not yet there. Select three any ingredients and click the "Cook" button.'),
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
    $form['inventory_set'][$type] = [
      '#type' => 'fieldset',
      '#title' => $item['title'],
      '#collapsible' => TRUE,
      '#collapsed' => !$item['options'],
      '#attributes' => [
        'class' => $item['classes'],
      ],
    ];
    if (!$item['options']) {
      $form['inventory_set'][$type]['items'] = [
        '#markup' => $item['message_if_null'],
      ];
    }
    else {
      $form['inventory_set'][$type]['items'] = [
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
      'callback' => 'custom_inventory_ajax_callback',
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
 * Inventory form ajax submit.
 *
 * {@inheritdoc}
 * @throws \Exception
 */
function custom_inventory_ajax_callback($form, &$form_state) {
  global $user;

  // Fetch selected by user consumables ID's.
  $consumables_sets = $form_state['values']['inventory_set'];

  // Check what type of food or bait user crafts.
  $consumable_type = '';
  $selected_consumables = [];
  foreach ($consumables_sets as $type => $set) {
    if (count(array_filter($set['items']))) {
      $selected_consumables = $set['items'];
      $consumable_type = $type;
      break;
    }
  }
  // Filter from unnecessary values.
  $selected_consumables = array_filter($selected_consumables, function ($v) {
    return is_string($v);
  }, ARRAY_FILTER_USE_BOTH);

  if (count($selected_consumables) === 3) {
    $user_consumables = explode(',', $user->consumables);
    // Remove used consumables from DB.
    foreach ($selected_consumables as $value) {
      unset($user_consumables[$value]);
    }
    // Add bait.
    switch ($consumable_type) {
      case 'food':
        array_push($user_consumables, 17);
        break;

      case 'bait_1':
        array_push($user_consumables, 18);
        break;

      case 'bait_2':
        array_push($user_consumables, 19);
        break;

      case 'bait_3':
        array_push($user_consumables, 20);
        break;
    }
    $user->consumables = implode(',', $user_consumables);

    user_save($user);
  }

  $custom_inventory_form = drupal_get_form('custom_inventory_form');
  $commands = [];
  $commands[] = ajax_command_replace(
    '#custom-inventory-form',
    '<div id="custom-inventory-form">' . drupal_render($custom_inventory_form) . '</div>'
  );

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Button set bait to catch.
 *
 * {@inheritdoc}
 * @throws \Exception
 */
function custom_set_bait_ajax_callback($form, &$form_state) {
  global $user;

  // Fetch selected by user consumables ID's.
  $consumables_sets = $form_state['values']['inventory_set'];

  // Check what type of food or bait user crafts.
  $selected_consumables = [];
  foreach ($consumables_sets as $type => $set) {
    if (count(array_filter($set['items']))) {
      $selected_consumables = $set['items'];
      break;
    }
  }
  // Filter from unnecessary values.
  $selected_consumables = array_filter($selected_consumables, function ($v) {
    return is_string($v);
  }, ARRAY_FILTER_USE_BOTH);

  $user_consumables = explode(',', $user->consumables);
  // Remove used consumable from DB.
  foreach ($selected_consumables as $value) {
    $user->catch = $user_consumables[$value];
    unset($user_consumables[$value]);
  }
  $user->consumables = implode(',', $user_consumables);

  user_save($user);

  $custom_catch_form = drupal_get_form('custom_catch_form');
  $custom_inventory_form = drupal_get_form('custom_inventory_form');
  $commands = [];
  $commands[] = ajax_command_replace(
    '#custom-catch-form',
    '<div id="custom-catch-form">' . drupal_render($custom_catch_form) . '</div>'
  );
  $commands[] = ajax_command_replace(
    '#custom-inventory-form',
    '<div id="custom-inventory-form">' . drupal_render($custom_inventory_form) . '</div>'
  );

  return ['#type' => 'ajax', '#commands' => $commands];
}
