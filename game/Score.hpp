#ifndef SCORE_HPP
#define SCORE_HPP

class Score {
  explicit Score(unsigned maxPoint);
  unsigned getLeftPlayerPoints() const;
  unsigned getRightPlayerPoints() const;
  void leftPlayerScore();
  void rightPlayerScore();

 private:
  unsigned mMaxPoints;
  unsigned mLeftPlayerPoints;
  unsigned mRightPlayerPoints;
};

#endif  // SCORE_HPP
