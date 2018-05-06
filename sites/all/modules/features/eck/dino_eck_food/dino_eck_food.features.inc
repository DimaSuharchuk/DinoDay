<?php
/**
 * @file
 * dino_eck_food.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function dino_eck_food_eck_bundle_info() {
  $items = array(
    'food_food' => array(
      'machine_name' => 'food_food',
      'entity_type' => 'food',
      'name' => 'food',
      'label' => 'Food',
      'config' => array(
        'managed_properties' => array(
          'picture' => 'picture',
          'food_type' => 'food_type',
          'name' => 'name',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function dino_eck_food_eck_entity_type_info() {
  $items = array(
    'food' => array(
      'name' => 'food',
      'label' => 'Food',
      'properties' => array(
        'picture' => array(
          'label' => 'Picture',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'food_type' => array(
          'label' => 'Food type',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'name' => array(
          'label' => 'Name',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
      ),
    ),
  );
  return $items;
}
