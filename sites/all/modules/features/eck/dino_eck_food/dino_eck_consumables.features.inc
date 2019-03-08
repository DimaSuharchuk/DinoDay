<?php

/**
 * @file
 * dino_eck_consumables.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function dino_eck_consumables_eck_bundle_info() {
  $items = array(
    'consumables_consumables' => array(
      'machine_name' => 'consumables_consumables',
      'entity_type' => 'consumables',
      'name' => 'consumables',
      'label' => 'Consumables',
      'config' => array(
        'managed_properties' => array(
          'picture' => 'picture',
          'consumable_type' => 'consumable_type',
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
function dino_eck_consumables_eck_entity_type_info() {
  $items = array(
    'consumables' => array(
      'name' => 'consumables',
      'label' => 'Consumables',
      'properties' => array(
        'picture' => array(
          'label' => 'Picture',
          'type' => 'text',
          'behavior' => 'textfield',
        ),
        'consumable_type' => array(
          'label' => 'Consumable type',
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
