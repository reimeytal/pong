#include <gml/gml.hpp>
#include <iostream>

#include "player.hpp"
#include "../paddle/paddle.hpp"
#include "../ball/ball.hpp"
#include "../bounding-box/bounding-box.hpp"

namespace pong{
  Player::Player(gml::vec3 paddlePos, BoundingBox opponentGoal)
  :score(0), opponentGoal(opponentGoal), paddle(Paddle()) {
    paddle.setPosition(paddlePos);
  }

  void Player::checkGoal(Ball& ball){
    if(ball.getBoundingBox().collides_with(opponentGoal)){
      score++;
      ball.reset();
    }
  }
}
