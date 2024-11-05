# Commerce Reports

This module provides a reporting system for Drupal Commerce.

Some features that you will find in this module:

* Table-based reports for sales with filtering by order status and date ranges.
  The report can break sales down monthly, weekly and daily.
* Table-based reports for customers, products and payment methods.
* An advanced reports dashboard showing a summarized view for all the above
  reports, visualization done by Charts module, using Google Charts.
* The ability to export to CSV files when Views Data Export is enabled.

## Sub-modules

### Commerce Reports Tax

The tax reporting module uses the Batch API to generate reports. It is able to
handle multiple reports with a variety of parameters, which are handled through
the Entity API.

### Commerce Reports Geckoboard

This sub-module provides integration with Geckoboard allowing for reporting
information about your revenue, sales and orders.

### Commerce Reports Stock

The stock calculates stock reports.

## Notes

1. Order created dates

Commerce Reports is based off of an order's CREATED date. Some modules, such as
Commerce Google Analytics trigger on an order's checkout completion. To provide
a better reporting environment it is recommended to enable the "Set the order
created date to the checkout completion date" rule. This will change an order's
created date to the check out time and synchronize Commerce Reports with
Commerce Google Analytics.

2. Product reports line item types

The product report is filtered to just the Product line item type. If your
Commerce site utilizes custom line items they will have to be enabled through
Views UI. This is default so that shipping line items and possible feed line
items are not accounted for.

3. Excluding fees or other price components

There is Commerce price by components module which provides a field formatter
that will exclude price components from being included in a rendered price.

https://www.drupal.org/project/commerce_price_components

## Installation

* Install this module using the [official Backdrop CMS instructions](https://backdropcms.org/guide/modules)

## Current Maintainers

* Seeking

## Credit

Originally maintained on Drupal by:

* [centarro](https://www.drupal.org/u/centarro)
* [jsacksick](https://www.drupal.org/u/jsacksick)
* [rszrama](https://www.drupal.org/u/rszrama)
* [mglaman](https://www.drupal.org/u/mglaman)
* [tomtech](https://www.drupal.org/u/tomtech)
* [aidanlis](https://www.drupal.org/u/aidanlis)

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.

