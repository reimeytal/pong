#ifndef PONG_SCORE_HPP
#define PONG_SCORE_HPP
#include <gml/gml.hpp>
#include "../shader/shader.hpp"
#include "../entity/entity.hpp"

namespace pong{
  class Score : public Entity{
  private:
    static unsigned int vao, vbo, ibo;
    static unsigned int textures[12];
    unsigned int scoreID;
  public:
    static void init();
    static void uninit();

    Score();
    void draw(const Shader&, const gml::mat4&) const;
    void setScore(unsigned int);
  };
}

#endif //PONG_SCORE_HPP
