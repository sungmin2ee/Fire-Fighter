#ifndef FIRE_FIGHTER_PLAYER_H
#define FIRE_FIGHTER_PLAYER_H

#include <vector>
#include "entity.h"
#include <SFML/Audio.hpp>
#include "settings.h"
#include "barrier.h"
#include "enemy.h"
#include "metrics.h"
#include <iostream>
#include <string>
#include "enemywave.h"

/**
 * @class Player
 * @author Sungmin Lee
 * @brief Manages the player's behavior and state in the game.
 *
 * The Player class is responsible for controlling the player's movements, handling shooting mechanics,
 * detecting collisions with enemies and barriers, and managing the player's health and speed.
 * It extends the Entity class, utilizing its position and texture properties.
 */
class Player : public Entity {
public:
    /**
     * @brief Constructs a Player object with initial position and game resolution.
     * Initializes player's properties such as movement speed, health, and sets up the sound effects for shooting.
     */
    Player(sf::RenderWindow& window);

    /**
     * @brief Destructor for Player, cleans up allocated resources.
     */
    virtual ~Player();

    /**
     * @brief Fires a bullet, adding it to the bullets vector.
     *
     * Creates a Bullet instance at the player's current position and plays a shooting sound effect if enabled.
     */
    void shoot();

    /**
     * @brief Updates the state and position of bullets, checks for collisions with enemies.
     * @param delta Time elapsed since the last frame.
     * @param enemyWave The current wave of enemies to check for collisions.
     * @param metrics Metrics object for updating game statistics like score.
     */
    void updateBullets(const sf::Time& delta, EnemyWave& enemyWave, Metrics& metrics);

    /**
     * @brief Updates bullets for collisions with barriers and handles the barrier shrinking.
     * @param delta Time elapsed since the last frame.
     * @param barrier The barrier instance to check for bullet collisions.
     */
    void updateBarrier(const sf::Time delta, Barrier& barrier);

    /**
     * @brief Draws bullets on the given render window.
     * @param window The window where bullets will be drawn.
     */
    void drawBullets(sf::RenderWindow& window);

    /**
     * @brief Moves the player in the given direction.
     * @param direction The vector indicating direction and magnitude of the movement.
     */
    void move(const sf::Vector2f& direction);

    /**
     * @brief Draws the player Sprite on the specified window.
     * @param window The render window to draw the player on.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Gets the size of the player's bulletSprite.
     * @return The size of the player's bulletSprite as an sf::Vector2f.
     */
    sf::Vector2f getSize() const;

    /**
     * @brief Sets the player's life count.
     * @param lives New number of lives for the player.
     */
    void setLives(int lives);

    /**
     * @brief Retrieves the current number of lives the player has.
     * @return Current number of lives.
     */
    int getLives() const;

    /**
     * @brief Decreases the player's life count by one.
     */
    void decreaseLife();

    /**
     * @brief Increases the player's life count by one, not exceeding the maximum which is 3.
     */
    void increaseLife();
    /**
     * @brief Reset player's position and lives
     */
    void reset(sf::RenderWindow& window);
    /**
     * @brief Checks for collision between the player and an enemy's sprite.
     * @param enemySprite The Sprite of the enemy to check for collision.
     * @return True if the player is colliding with the enemy bulletSprite, false otherwise.
     */
    bool isCollidingWithEnemy(const sf::Sprite& enemySprite) const;

    /**
     * @brief Sets the texture for the player's bulletSprite.
     * @param t The file path to the texture.
     */
    void setPlayerTexture(char *t);

private:
    float movementSpeed; ///< The player's movement speed.
    int lives; ///< The number of lives the player has.
    sf::SoundBuffer shootBuffer; ///< Buffer for the shooting sound effect.
    sf::Sound shootSound; ///< Sound effect for shooting.
    Settings *options; ///< Pointer to game settings, used for sound toggling.
};

#endif //FIRE_FIGHTER_PLAYER_H
