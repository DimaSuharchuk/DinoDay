<?php

/**
 * @file
 * Consumables info for batch.
 */

/**
 * Helper function returns array with all consumables.
 *
 * @return array
 */
function _get_consumables() {
  $consumables = [];

  // Fish.
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/fish/fish.svg',
    'consumable_type' => 'Морепродукты',
    'name' => 'Лящ',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/fish/octopus.svg',
    'consumable_type' => 'Морепродукты',
    'name' => 'Осьминог',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/fish/salmon.svg',
    'consumable_type' => 'Морепродукты',
    'name' => 'Лосось',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/fish/shrimp.svg',
    'consumable_type' => 'Морепродукты',
    'name' => 'Креветка',
  ];
  // Fruits.
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/fruits/apple.svg',
    'consumable_type' => 'Фрукты',
    'name' => 'Яблоко',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/fruits/fig.svg',
    'consumable_type' => 'Фрукты',
    'name' => 'Фига',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/fruits/pear.svg',
    'consumable_type' => 'Фрукты',
    'name' => 'Груша',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/fruits/pineapple.svg',
    'consumable_type' => 'Фрукты',
    'name' => 'Ананас',
  ];
  // Meat.
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/meat/bacon.svg',
    'consumable_type' => 'Мясо',
    'name' => 'Бекон',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/meat/meat.svg',
    'consumable_type' => 'Мясо',
    'name' => 'Курочка',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/meat/meat-1.svg',
    'consumable_type' => 'Мясо',
    'name' => 'Окорок',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/meat/steak.svg',
    'consumable_type' => 'Мясо',
    'name' => 'Стейк',
  ];
  // Vegetables.
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/vegetables/broccoli.svg',
    'consumable_type' => 'Овощи',
    'name' => 'Брокколи',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/vegetables/cabbage.svg',
    'consumable_type' => 'Овощи',
    'name' => 'Капуста',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/vegetables/carrot.svg',
    'consumable_type' => 'Овощи',
    'name' => 'Морковка',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/vegetables/tomato.svg',
    'consumable_type' => 'Овощи',
    'name' => 'Томат',
  ];
  // Bait.
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/other/dish.svg',
    'consumable_type' => 'Наживка',
    'name' => 'Наживка ур. I',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/other/dish.svg',
    'consumable_type' => 'Наживка',
    'name' => 'Наживка ур. II',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/other/dish.svg',
    'consumable_type' => 'Наживка',
    'name' => 'Наживка ур. III',
  ];
  $consumables[] = [
    'picture' => FOOD_PICTURE_DIR . '/other/dish.svg',
    'consumable_type' => 'Наживка',
    'name' => 'Наживка ур. IV',
  ];

  return $consumables;
}
