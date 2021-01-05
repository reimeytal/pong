#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdint>
#include "../paddle/paddle.hpp"
#include "../ball/ball.hpp"
#include "../bounding-box/bounding-box.hpp"

namespace pong{
    class Player{
    private:
      uint8_t score;
      BoundingBox opponentGoal;
    public:
      Paddle paddle;

      Player(gml::vec3 paddlePos, BoundingBox opponentGoal);
      void checkGoal(Ball& ball);
    };
}

#endif //PLAYER_HPP