<?php
/**
 * @file
 * Food info for batch.
 */

/**
 * Helper function returns array with all food.
 *
 * @return array
 */
function _get_food() {
  $food = [];

  // Fish.
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/fish/fish.svg',
    'food_type' => 'Морепродукты',
    'name' => 'Лящ',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/fish/octopus.svg',
    'food_type' => 'Морепродукты',
    'name' => 'Осьминог',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/fish/salmon.svg',
    'food_type' => 'Морепродукты',
    'name' => 'Лосось',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/fish/shrimp.svg',
    'food_type' => 'Морепродукты',
    'name' => 'Креветка',
  ];
  // Fruits.
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/fruits/apple.svg',
    'food_type' => 'Фрукты',
    'name' => 'Яблоко',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/fruits/fig.svg',
    'food_type' => 'Фрукты',
    'name' => 'Фига',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/fruits/pear.svg',
    'food_type' => 'Фрукты',
    'name' => 'Груша',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/fruits/pineapple.svg',
    'food_type' => 'Фрукты',
    'name' => 'Ананас',
  ];
  // Meat.
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/meat/bacon.svg',
    'food_type' => 'Мясо',
    'name' => 'Бекон',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/meat/meat.svg',
    'food_type' => 'Мясо',
    'name' => 'Курочка',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/meat/meat-1.svg',
    'food_type' => 'Мясо',
    'name' => 'Окорок',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/meat/steak.svg',
    'food_type' => 'Мясо',
    'name' => 'Стейк',
  ];
  // Vegetables.
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/vegetables/broccoli.svg',
    'food_type' => 'Овощи',
    'name' => 'Брокколи',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/vegetables/cabbage.svg',
    'food_type' => 'Овощи',
    'name' => 'Капуста',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/vegetables/carrot.svg',
    'food_type' => 'Овощи',
    'name' => 'Морковка',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/vegetables/tomato.svg',
    'food_type' => 'Овощи',
    'name' => 'Томат',
  ];
  // Bait.
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/other/dish.svg',
    'food_type' => 'Наживка',
    'name' => 'Наживка ур. I',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/other/dish.svg',
    'food_type' => 'Наживка',
    'name' => 'Наживка ур. II',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/other/dish.svg',
    'food_type' => 'Наживка',
    'name' => 'Наживка ур. III',
  ];
  $food[] = [
    'picture' => FOOD_PICTURE_DIR . '/other/dish.svg',
    'food_type' => 'Наживка',
    'name' => 'Наживка ур. IV',
  ];

  return $food;
}
