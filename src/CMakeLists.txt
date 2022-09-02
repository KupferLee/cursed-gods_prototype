cmake_minimum_required(VERSION 3.11)

include(../cmake/raylib.cmake)

include(../cmake/nlohmann_json.cmake)

project(CursedGods VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



add_executable(${PROJECT_NAME} main.cpp player.h player.cpp GameObject.h Actor.h ProtectedTexture.cpp ProtectedTexture.h ProtectedTileset.cpp ProtectedTileset.h Scene.cpp Scene.h item_base.h item_ring.cpp item_ring.h Inventory.cpp Inventory.h InventoryTemplate.h item_sword.cpp item_sword.h BattleActor.cpp BattleActor.h BattlePlayer.cpp BattlePlayer.h BattleRat.cpp BattleRat.h BattleHarpye.cpp BattleHarpye.h BattleScreen.cpp BattleScreen.h DRAW.h Actor.cpp ActorHarpye.cpp ActorHarpye.h ActorLoredrop.cpp ActorLoredrop.h ActorRat.cpp ActorRat.h ActorItemSword.cpp ActorItemSword.h ActorItemRing.cpp ActorItemRing.h item_flower.cpp item_flower.h ActorItemFlower.cpp ActorItemFlower.h)



# Add config.h.in file
configure_file(config.h.in config.h)
target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

#  Link to Raylib
target_link_libraries(${PROJECT_NAME} raylib nlohmann_json::nlohmann_json)

# Copy assets to assets path
add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_LIST_DIR}/../cmake/copy-assets.cmake"
        )
add_dependencies(${PROJECT_NAME} copy_assets)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()

# CPack instructions
# call e.g. cpack -G ZIP -C Debug to create a binary distribution
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${PROJECT_NAME}_Bundle")
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/assets" DESTINATION "${PROJECT_NAME}_Bundle")