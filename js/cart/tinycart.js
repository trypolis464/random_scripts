/*
 * cart.
 * Basic JavaScript shoppingcart.
 * 
 * Copyright (C) 2021, Ty Gillespie. All rights reserved.
 * MIT License.
 * 
 * Initial code from: https://github.com/munissor/tiny-cart
 */

"use strict";

let cart = {};

// Add an item with the given name and price to the cart.
function addToCart(name, price) {
  let item = cart[name] || {price: price, quantity: 0};
  item.price = price;
  item.quantity = item.quantity + 1;
  cart[name] = item;
  updateCartElements();
}

// Remove all items with the given name from the cart.
function removeFromCart(name) {
  delete cart[name];
  updateCartElements();
}

// Update the cart.
function updateCartElements() {
  let $cart = $("#cart");
  $cart.empty();
  let $list = $("<ul></ul>");
  for (let item in cart) {
    if (cart.hasOwnProperty(item)) {
      let data = cart[item];
      let $item = $("<li><span>" + item + "<span> - <span>" + data.quantity + "x (" + data.price * data.quantity + " &dollar;)<span><a href=\"javascript:removeFromCart('" + item + "')\">[remove]</a></li>");
      $list.append($item);
    }
  }
  $cart.append($list);
}
