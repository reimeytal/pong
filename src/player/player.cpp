#include <gml/gml.hpp>

#include "player.hpp"
#include "../paddle/paddle.hpp"
#include "../ball/ball.hpp"
#include "../score/score.hpp"
#include "../bounding-box/bounding-box.hpp"

namespace pong{
  Player::Player(gml::vec3 paddlePos, BoundingBox opponentGoal, gml::vec3 scorePosition)
  :score(0), opponentGoal(opponentGoal), paddle(Paddle()), scoreClass(Score(gml::vec3(0.2f, 0.2f, 1.0f), scorePosition)) {
    paddle.setPosition(paddlePos);
  }

  bool Player::checkGoal(Ball& ball){
    if(ball.getBoundingBox().collides_with(opponentGoal)){
      score++;
      scoreClass.setScore(score);
      ball.reset();
    }
    if(score == 10){
      return true;
    }
    return false;
  }
}
