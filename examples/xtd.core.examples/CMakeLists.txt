cmake_minimum_required(VERSION 3.3)

project(xtd.core.examples)
find_package(xtd REQUIRED)

add_projects(
  hello_worlds
  collections
  console
  delegates
  diagnostics
  environment
  format
  guid
  keywords
  mains
  network
  processes
  random
  sprintf
  strings
  web
  others
  tests
)

