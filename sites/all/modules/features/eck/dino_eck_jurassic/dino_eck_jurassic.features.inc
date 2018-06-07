<?php
/**
 * @file
 * dino_eck_jurassic.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function dino_eck_jurassic_eck_bundle_info() {
  $items = array(
    'jurassic_jurassic' => array(
      'machine_name' => 'jurassic_jurassic',
      'entity_type' => 'jurassic',
      'name' => 'jurassic',
      'label' => 'Jurassic',
      'config' => array(
        'managed_properties' => array(
          'pictures' => 'pictures',
          'name' => 'name',
          'consume' => 'consume',
          'description' => 'description',
          'price' => 'price',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function dino_eck_jurassic_eck_entity_type_info() {
  $items = array(
    'jurassic' => array(
      'name' => 'jurassic',
      'label' => 'Jurassic',
      'properties' => array(
        'pictures' => array(
          'label' => 'Pictures',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'name' => array(
          'label' => 'Name',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'consume' => array(
          'label' => 'Consume',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'description' => array(
          'label' => 'Description',
          'type' => 'long_text',
          'behavior' => 'long_text',
        ),
        'price' => array(
          'label' => 'Price',
          'type' => 'integer',
          'behavior' => 'integer',
        ),
      ),
    ),
  );
  return $items;
}
