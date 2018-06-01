<?php
/**
 * @file
 * Dinosaurs info for batch.
 */

/**
 * Helper function returns array with all dinosaurs.
 *
 * @return array
 */
function _get_dinosaurs() {
  $dinosaurs = [];

  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/alamozavr.svg',
    'name' => 'Аламозавр',
    'grade' => 1,
    'food_type' => 'Фрукты',
    'favorite_food' => 'Яблоко',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/amurozavr.svg',
    'name' => 'Амурозавр',
    'grade' => 1,
    'food_type' => 'Морепродукты',
    'favorite_food' => 'Лящ',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/brahiozavr.svg',
    'name' => 'Брахиозавр',
    'grade' => 1,
    'food_type' => 'Мясо',
    'favorite_food' => 'Бекон',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/cherepozavr.svg',
    'name' => 'Черепозавр',
    'grade' => 1,
    'food_type' => 'Фрукты',
    'favorite_food' => 'Фига',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/izizavr.svg',
    'name' => 'Изизавр',
    'grade' => 1,
    'food_type' => 'Морепродукты',
    'favorite_food' => 'Осьминог',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/kusatops.svg',
    'name' => 'Кусатопс',
    'grade' => 1,
    'food_type' => 'Мясо',
    'favorite_food' => 'Курочка',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/mapuzavr.svg',
    'name' => 'Мапузавр',
    'grade' => 1,
    'food_type' => 'Овощи',
    'favorite_food' => 'Брокколи',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/mimizavr.svg',
    'name' => 'Мимизавр',
    'grade' => 1,
    'food_type' => 'Фрукты',
    'favorite_food' => 'Груша',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/pamparaptor.svg',
    'name' => 'Пампараптор',
    'grade' => 1,
    'food_type' => 'Морепродукты',
    'favorite_food' => 'Лосось',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/pentidrako.svg',
    'name' => 'Пентидрако',
    'grade' => 1,
    'food_type' => 'Фрукты',
    'favorite_food' => 'Ананас',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/plateozavr.svg',
    'name' => 'Платеозавр',
    'grade' => 1,
    'food_type' => 'Мясо',
    'favorite_food' => 'Окорок',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/tryceratops.svg',
    'name' => 'Трицератопс',
    'grade' => 1,
    'food_type' => 'Морепродукты',
    'favorite_food' => 'Креветка',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/tsaraptor.svg',
    'name' => 'Цараптор',
    'grade' => 1,
    'food_type' => 'Мясо',
    'favorite_food' => 'Стейк',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/tselur.svg',
    'name' => 'Целюр',
    'grade' => 1,
    'food_type' => 'Овощи',
    'favorite_food' => 'Капуста',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/1/yamatseratops.svg',
    'name' => 'Ямацератопс',
    'grade' => 1,
    'food_type' => 'Овощи',
    'favorite_food' => 'Морковка',
  ];
  // 2
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/diplodoc.svg',
    'name' => 'Диплодок',
    'grade' => 2,
    'food_type' => 'Фрукты',
    'favorite_food' => 'Яблоко',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/kapitozavr.svg',
    'name' => 'Капитозавр',
    'grade' => 2,
    'food_type' => 'Фрукты',
    'favorite_food' => 'Фига',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/lokozavr.svg',
    'name' => 'Локозавр',
    'grade' => 2,
    'food_type' => 'Фрукты',
    'favorite_food' => 'Груша',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/minozavr.svg',
    'name' => 'Минозавр',
    'grade' => 2,
    'food_type' => 'Морепродукты',
    'favorite_food' => 'Лящ',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/multizavr.svg',
    'name' => 'Мультизавр',
    'grade' => 2,
    'food_type' => 'Морепродукты',
    'favorite_food' => 'Осьминог',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/pentatseratops.svg',
    'name' => 'Пентацератопс',
    'grade' => 2,
    'food_type' => 'Мясо',
    'favorite_food' => 'Бекон',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/stegozavr.svg',
    'name' => 'Стегозавр',
    'grade' => 2,
    'food_type' => 'Овощи',
    'favorite_food' => 'Томат',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/superzavr.svg',
    'name' => 'Суперзавр',
    'grade' => 2,
    'food_type' => 'Овощи',
    'favorite_food' => 'Брокколи',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/uranozavr.svg',
    'name' => 'Уранозавр',
    'grade' => 2,
    'food_type' => 'Овощи',
    'favorite_food' => 'Капуста',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/2/zahazmozavr.svg',
    'name' => 'Захазмозавр',
    'grade' => 2,
    'food_type' => 'Мясо',
    'favorite_food' => 'Курочка',
  ];
  // 3
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/3/brontozavr.svg',
    'name' => 'Бронтозавр',
    'grade' => 3,
    'food_type' => 'Фрукты',
    'favorite_food' => 'Ананас',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/3/shypast.svg',
    'name' => 'Шипаст',
    'grade' => 3,
    'food_type' => 'Морепродукты',
    'favorite_food' => 'Лосось',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/3/skalozavr.svg',
    'name' => 'Скалозавр',
    'grade' => 3,
    'food_type' => 'Овощи',
    'favorite_food' => 'Морковка',
  ];
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/3/tyranozavr.svg',
    'name' => 'Тиранозавр',
    'grade' => 3,
    'food_type' => 'Мясо',
    'favorite_food' => 'Окорок',
  ];
  // 4
  $dinosaurs[] = [
    'picture' => DINO_PICTURE_DIR . '/4/nanotyran.svg',
    'name' => 'Нанотиран',
    'grade' => 4,
    'food_type' => 'Мясо',
    'favorite_food' => 'Стейк',
  ];

  return $dinosaurs;
}
