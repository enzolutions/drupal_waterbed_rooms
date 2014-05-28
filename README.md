Drupal Waterbed Rooms
=====================

Waterbed Rooms is a Drupal 7 Feature to create a website similar to http://airbnb.com with minimal features.

## Download

````
$ git clone git@github.com:enzolutions/drupal_waterbed_rooms.git
````

## Tweaks and Tricks included

This Feature includes some pretty cool tweaks and tricks. You can read more about them on the waterbed_rooms.module file.

Some of my favorites include:

* Custom Image Formatter for Services (Uses an absolute path with an option to define an image style preset).

* View query alter used to add an extra “Group By”.

* Creates a custom Service Resource (node_waterbed) to return some extra information about the owner. Also it enables field_pictures to return absolute paths.

## Drupal Dependencies

* <a target="_blank" href="drupal.org/project/features">Features</a>.
* <a target="_blank" href="drupal.org/project/date">Date</a>.
* <a target="_blank" href="drupal.org/project/commerce">Commerce</a>.
* <a target="_blank" href="https://drupal.org/project/entityreference">Entityreference</a>.
* <a target="_blank" href="https://drupal.org/project/rules">Rules</a>.
* <a target="_blank" href="https://drupal.org/project/geocoder">Geocoder</a>.
* <a target="_blank" href="https://drupal.org/project/geocoder_autocomplete">Geocoder_autocomplete</a>.
* <a target="_blank" href="https://drupal.org/project/geofield">Geofield</a>.
* <a target="_blank" href="https://drupal.org/project/services">Services</a>.
* <a target="_blank" href="https://drupal.org/project/services_views">Services_views</a>
* <a target="_blank" href="https://drupal.org/project/views">Views</a>
* <a target="_blank" href="drupal.org/project/rooms">Rooms</a>
* <a target="_blank" href="https://drupal.org/sandbox/ziomizar/2086255">Rooms_node</a>. (Sandbox)
* <a target="_blank" href="https://drupal.org/project/cors">Cors</a>

## Installation.

Before enabling the Feature Waterbed Rooms, I recommend installing the Rooms module, because it could get a little tricky. You can find instructions on how to do that at <a target="_blank" href="http://www.drupalrooms.com/docs"></a>http://www.drupalrooms.com/docs</a> (don't forget the libraries section).

Another requirement is applying the patch <a target="_blank"href="https://drupal.org/node/2274681#comment-8816065"></a>https://drupal.org/node/2274681#comment-8816065</a> to Sandbox module Rooms Node.

After you enable the Waterbed Rooms feature, you are required to edit the Content Type "Standard Doubles" (/admin/structure/types/manage/room-standard-doubles) and enable the contact type as a Room Node. (see image)

![Edit Content Type Standard Doubles](https://raw.githubusercontent.com/enzolutions/drupal_waterbed_rooms/master/images/edit_room_availability.png "Edit Content Type Standard Doubles")


After creating some Standard Doubles nodes, you need to update the room availability (i.e.: http://YOURDOMAIN/node/1/availability) (see image)

![Editing Room Node Availablity](https://raw.githubusercontent.com/enzolutions/drupal_waterbed_rooms/master/images/edit_room_node_content_type.png "Editing Room Node Availablity")


### Usage

The goal of this project is to create a backend for a service similar to Airbnb, after completing the installation steps and creating some Room Nodes with availability you will be ready to consume the API and fetch room information.

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

You can combine price and date filtering. In any case we will a get JSON response similar to next example.

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

You can check out a live demo at <a target="_blank"href="http://waterbed-backend.7sabores.com/api/views/waterbed.json">http://waterbed-backend.7sabores.com/api/views/waterbed.json</a>.

#### CORS

If you’re planning to use your own server to test, remember use the CORS module to enable CORS requests and avoid errors related to invalid client requests because the client isn't located under same domain.Just go to http://YOURDOMAIN/admin/config/services/cors and do a similar setting as suggested below.

````
api/*|http://localhost:8080|POST,ADD,GET,PUT,DELETE,OPTIONS|X-CSRF-Token|true
````

Your port is necessary only if you use other port than 80
