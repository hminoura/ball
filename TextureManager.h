#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

// TODO: complete TextureManager class as Singleton
class TextureManager {
  std::unordered_map<std::string, sf::Texture> textures;

public:
  sf::Texture* get(const std::string& filename);
};
