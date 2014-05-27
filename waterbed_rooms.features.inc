<?php
/**
 * @file
 * waterbed_rooms.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function waterbed_rooms_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function waterbed_rooms_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function waterbed_rooms_image_default_styles() {
  $styles = array();

  // Exported image style: waterbed__260x195_.
  $styles['waterbed__260x195_'] = array(
    'name' => 'waterbed__260x195_',
    'label' => 'waterbed (260x195)',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 260,
          'height' => 195,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function waterbed_rooms_node_info() {
  $items = array(
    'room_standard_doubles' => array(
      'name' => t('Standard Doubles'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Legend'),
      'help' => '',
    ),
    'unit_description' => array(
      'name' => t('Unit Description'),
      'base' => 'node_content',
      'description' => t('Bookable Unit Description.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_rooms_unit_type().
 */
function waterbed_rooms_default_rooms_unit_type() {
  $items = array();
  $items['deluxe_doubles'] = entity_import('rooms_unit_type', '{
    "type" : "deluxe_doubles",
    "label" : "Deluxe Doubles",
    "weight" : "0",
    "data" : {
      "base_price" : "125",
      "min_sleeps" : "1",
      "max_sleeps" : "4",
      "min_children" : "1",
      "max_children" : "2",
      "rooms_description_source" : ""
    },
    "rdf_mapping" : []
  }');
  $items['standard_doubles'] = entity_import('rooms_unit_type', '{
    "type" : "standard_doubles",
    "label" : "Standard Doubles",
    "weight" : "0",
    "data" : {
      "base_price" : "45",
      "min_sleeps" : "1",
      "max_sleeps" : "2",
      "min_children" : "0",
      "max_children" : "1",
      "rooms_description_source" : ""
    },
    "rdf_mapping" : []
  }');
  return $items;
}
