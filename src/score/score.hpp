#ifndef PONG_SCORE_HPP
#define PONG_SCORE_HPP
#include <gml/gml.hpp>
#include "../shader/shader.hpp"
#include "../entity/entity.hpp"
#include "../bounding-box/bounding-box.hpp"

namespace pong{
  class Score : public Entity{
  private:
    static unsigned int vao, vbo, ibo;
    static unsigned int textures[12];
    static unsigned int nextID;
    unsigned int scoreID;
  public:
    static void init();
    static void uninit();

    Score(gml::vec3, gml::vec3);
    void draw(const Shader&, const gml::mat4&) const;
    void setScore(unsigned int);
    BoundingBox getBoundingBox();
  };
}

#endif //PONG_SCORE_HPP
