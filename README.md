# esp32_reloc_dirs

ESP-IDF Project Subdir Relocate Example

## This is tricky

Here was some useful help - 

- [How to relocate or rename main\ & build\ directories - esp32.io](http://forum.esp32.com/viewtopic.php?f=13&t=44878&sid=2a296088b0342d8d1ae8d63c3473828e)

## Relocate main\

Simple!

- [ESP-IDF Programming Guide - Renaming main Component](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html#rename-main)


### Renaming main Component

The build system provides special treatment to the main component. It is a component that gets automatically added to the build provided that it is in the expected location, PROJECT_DIR/main. All other components in the build are also added as its dependencies, saving the user from hunting down dependencies and providing a build that works right out of the box. Renaming the main component causes the loss of these behind-the-scenes heavy lifting, requiring the user to specify the location of the newly renamed component and manually specify its dependencies. Specifically, the steps to renaming main are as follows:

1. Rename main directory

2. Set EXTRA_COMPONENT_DIRS in the project CMakeLists.txt to include the renamed main directory

	a. Locate the Project CMakeLists.txt at the root
	
	b. create(set) or append(list) to EXTRA_COMPONENT_DIRS
	
	 set(EXTRA_COMPONENT_DIRS ${CMAKE_CURRENT_LIST_DIR}/Core)

3. Specify the dependencies in the renamed component's CMakeLists.txt file via REQUIRES or PRIV_REQUIRES arguments on component registration

	x