<?php

/**
 * @file
 * Theme and preprocess functions for page, html, etc
 */

/**
 * Implements hook_preprocess_HOOK() for page.html.twig.
 *
 * @Example. You can safely remove this hook completely.
 */
function STARTER_preprocess_page(array &$variables) {
  /** @var \Drupal\Core\Template\Attribute $main_layout_attributes */
  $main_layout_attributes = &$variables['main_layout_attributes'];

  // Set default class.
  $main_layout_attributes->addClass('main-layout');

  // Handle sidebar modifiers.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $main_layout_attributes->addClass('main-layout--two-sidebars');
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $main_layout_attributes->addClass('main-layout--sidebar-first');
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $main_layout_attributes->addClass('main-layout--sidebar-second');
  }
  else {
    $main_layout_attributes->addClass('main-layout--no-sidebars');
  }
}
