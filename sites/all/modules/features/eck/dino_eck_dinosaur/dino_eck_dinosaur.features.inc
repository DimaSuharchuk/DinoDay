<?php
/**
 * @file
 * dino_eck_dinosaur.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function dino_eck_dinosaur_eck_bundle_info() {
  $items = array(
    'dinosaur_dinosaur' => array(
      'machine_name' => 'dinosaur_dinosaur',
      'entity_type' => 'dinosaur',
      'name' => 'dinosaur',
      'label' => 'Dinosaur',
      'config' => array(
        'managed_properties' => array(
          'picture' => 'picture',
          'name' => 'name',
          'grade' => 'grade',
          'food_type' => 'food_type',
          'favorite_food' => 'favorite_food',
          'consume' => 'consume',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function dino_eck_dinosaur_eck_entity_type_info() {
  $items = array(
    'dinosaur' => array(
      'name' => 'dinosaur',
      'label' => 'Dinosaur',
      'properties' => array(
        'picture' => array(
          'label' => 'Picture',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'name' => array(
          'label' => 'Name',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'grade' => array(
          'label' => 'Grade',
          'type' => 'integer',
          'behavior' => 'integer',
        ),
        'food_type' => array(
          'label' => 'Food type',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'favorite_food' => array(
          'label' => 'Favorite food',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'consume' => array(
          'label' => 'Consume',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
      ),
    ),
  );
  return $items;
}
