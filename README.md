Drupal Waterbed Rooms
=====================

Waterbed Rooms is a Drupal 7 Feature to create a backend for a site like http://airbnb.com with minimal features.

## Tweaks and Tricks included

This Feature include some tweaks and tricks you can read inside the file waterbed_rooms.module

* Custom Image Fortatter for Services ( Absolute path with option to select an image style)
* View query alter to add extra group by
* Created custom Service Resource *node_waterbed* to return some extra information about owner and enable field_pictures to return absolute paths.

## Drupal Dependencies

* <a target="_blank" href="drupal.org/project/features">Features</a>.
* <a target="_blank" href="drupal.org/project/date">Date</a>.
* <a target="_blank" href="drupal.org/project/commerce">Commerce</a>.
* <a target="_blank" href="https://drupal.org/project/entityreference"></a>Entityreference</a>.
* <a target="_blank" href="https://drupal.org/project/rules">Rules</a>.
* <a target="_blank" href="https://drupal.org/project/geocoder">Geocoder</a>.
* <a target="_blank" href="https://drupal.org/project/geocoder_autocomplete">Geocoder_autocomplete</a>.
* <a target="_blank" href="https://drupal.org/project/geofield">Geofield</a>.
* <a target="_blank" href="https://drupal.org/project/services">Services</a>.
* <a target="_blank" href="https://drupal.org/project/services_views">Services_views</a>
* <a target="_blank" href="https://drupal.org/project/views"></a>Views</a>
* <a target="_blank" href="drupal.org/project/rooms">Rooms</a>
* <a target="_blank" href="https://drupal.org/sandbox/ziomizar/2086255">Rooms_node</a>. (Sandbox)
* <a target="_blank" href="https://drupal.org/project/cors">cors</a>

## Installation.

Before to enable the Feature Waterbed Rooms, I recommend install the Rooms module, becuase could be little tricky, you can find the instructions at <a target="_blank" href="http://www.drupalrooms.com/docs"></a>http://www.drupalrooms.com/docs</a> (don't forget the libraries section).

Is requiered apply the patch <a target="_blank"href="https://drupal.org/node/2274681#comment-8816065"></a>https://drupal.org/node/2274681#comment-8816065</a> to Sandbox module Rooms Node.

After enable Feature Module Waterbed Rooms, is required edit the Content Type "Standard Doubles" (http://YOURDOMAIN/admin/structure/types/manage/room-standard-doubles) to enable the contact type as a Room Node. (see image)

![Edit Content TYpe Standard Doubles](https://raw.githubusercontent.com/enzolutions/drupal_waterbed_rooms/master/images/edit_room_availability.png "Edit Content TYpe Standard Doubles")


After create "Standard Doubles" nodes,  is required update the room availabilty (http://YOURDOMAIN/node/1/availability) (see image)

![Editing Room Node Availablity](https://raw.githubusercontent.com/enzolutions/drupal_waterbed_rooms/master/images/edit_room_node_content_type.png "Editing Room Node Availablity")


### Usage

The goal of this project is to create a backend for a service similat to Airbnb, after complete the installation steps and create some Room Nodes with avalability you will be ready to consume the API to fetch rooms information.

#### Getting all rooms available

````
http://YOURDOMAIN/api/views/waterbed.json
````

#### Getting all rooms available in a range of dates.

````
http://YOURDOMAIN/api/views/waterbed.json?availabilty[min]=2014-5-20&availabilty[max]=2014-5-28
````

#### Getting all rooms available in a range of price
````
http://YOURDOMAIN/api/views/waterbed?price[min]=30&price[max]=45
````

You can combine price and date filtering. In any case we will a JSON response similar to next example.

````
[
  {
    nid: "1",
    legend: "Walk to downtown san jose from here. ",
    images: "http://waterbed-backend.7sabores.com/sites/default/files/styles/waterbed__260x195_/public/Atardecer-San-Jose.jpg?itok=R0sIs042, http://waterbed-backend.7sabores.com/sites/default/files/styles/waterbed__260x195_/public/62349C455.jpg?itok=Y_uonL9Y",
    rooms_availability_index_price: "45",
    latitude: "9.896970600000",
    longitude: "-84.061670900000",
    type: "Standard Doubles",
    date: "2014-05-27"
  },
  {
    nid: "2",
    legend: "Apartment in San José North Sabana",
    images: "http://waterbed-backend.7sabores.com/sites/default/files/styles/waterbed__260x195_/public/SAb-nor.-Condo-Bruno-24.jpg?itok=GuIkH3-v, http://waterbed-backend.7sabores.com/sites/default/files/styles/waterbed__260x195_/public/San-Jose-Real-Estate-Prices-Around-Parque-La-%20Sabana-Expected-To-Rise-Dramatically.jpg?itok=RD7Ip73F",
    rooms_availability_index_price: "60",
    latitude: "9.935231600000",
    longitude: "-84.102606200000",
    type: "Standard Doubles",
    date: "2014-05-27"
  }
]
````

You can check a live example at <a target="_blank"href="http://waterbed-backend.7sabores.com/api/views/waterbed.json">http://waterbed-backend.7sabores.com/api/views/waterbed.json</a>.
