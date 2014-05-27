<?php
/**
 * @file
 * waterbed_rooms.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function waterbed_rooms_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'waterbed';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Waterbed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Waterbed';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'legend';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Pictures */
  $handler->display->display_options['fields']['field_pictures']['id'] = 'field_pictures';
  $handler->display->display_options['fields']['field_pictures']['table'] = 'field_data_field_pictures';
  $handler->display->display_options['fields']['field_pictures']['field'] = 'field_pictures';
  $handler->display->display_options['fields']['field_pictures']['label'] = 'images';
  $handler->display->display_options['fields']['field_pictures']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pictures']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_pictures']['type'] = 'image_services';
  $handler->display->display_options['fields']['field_pictures']['settings'] = array(
    'image_style' => 'waterbed__260x195_',
  );
  $handler->display->display_options['fields']['field_pictures']['delta_offset'] = '0';
  /* Field: Rooms Node: Rooms Price */
  $handler->display->display_options['fields']['price']['id'] = 'price';
  $handler->display->display_options['fields']['price']['table'] = 'rooms_availability_index';
  $handler->display->display_options['fields']['price']['field'] = 'price';
  $handler->display->display_options['fields']['price']['label'] = '';
  $handler->display->display_options['fields']['price']['element_label_colon'] = FALSE;
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = 'latitude';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_address']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address_1']['id'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_1']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address_1']['label'] = 'longitude';
  $handler->display->display_options['fields']['field_address_1']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_address_1']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_address_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Rooms Node: Rooms Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'rooms_availability_index';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = 'date';
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'long';
  /* Sort criterion: Rooms Node: Rooms Date */
  $handler->display->display_options['sorts']['date']['id'] = 'date';
  $handler->display->display_options['sorts']['date']['table'] = 'rooms_availability_index';
  $handler->display->display_options['sorts']['date']['field'] = 'date';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'room_standard_doubles' => 'room_standard_doubles',
  );
  /* Filter criterion: Rooms Node: Rooms Status */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'rooms_availability_index';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value']['value'] = '1';
  /* Filter criterion: Rooms Node: Rooms Date */
  $handler->display->display_options['filters']['date']['id'] = 'date';
  $handler->display->display_options['filters']['date']['table'] = 'rooms_availability_index';
  $handler->display->display_options['filters']['date']['field'] = 'date';
  $handler->display->display_options['filters']['date']['operator'] = 'between';
  $handler->display->display_options['filters']['date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date']['expose']['operator_id'] = 'date_op';
  $handler->display->display_options['filters']['date']['expose']['label'] = 'Range Dates';
  $handler->display->display_options['filters']['date']['expose']['operator'] = 'date_op';
  $handler->display->display_options['filters']['date']['expose']['identifier'] = 'availabilty';
  $handler->display->display_options['filters']['date']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Rooms Node: Rooms Price */
  $handler->display->display_options['filters']['price']['id'] = 'price';
  $handler->display->display_options['filters']['price']['table'] = 'rooms_availability_index';
  $handler->display->display_options['filters']['price']['field'] = 'price';
  $handler->display->display_options['filters']['price']['operator'] = 'between';
  $handler->display->display_options['filters']['price']['exposed'] = TRUE;
  $handler->display->display_options['filters']['price']['expose']['operator_id'] = 'price_op';
  $handler->display->display_options['filters']['price']['expose']['label'] = 'Rooms Price';
  $handler->display->display_options['filters']['price']['expose']['operator'] = 'price_op';
  $handler->display->display_options['filters']['price']['expose']['identifier'] = 'price';
  $handler->display->display_options['filters']['price']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'waterbed';
  $export['waterbed'] = $view;

  return $export;
}
