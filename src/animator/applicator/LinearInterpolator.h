/* Linear Interpolator Applicator
 * Paul Wightmore 2015
 */
 
#ifndef _APPLICATOR_LINEARINTERPOLATOR_h
#define _APPLICATOR_LINEARINTERPOLATOR_h

#include "animator/IInterpolatingApplicator.h"

namespace Animator {
namespace Applicators {

//! Generic linear interpolator
/**
  * The target must implement basic overloading operators for + - and *(float)
  * \tparam T_Payload the type of the target
  */
template<typename T_Payload>
class LinearInterpolator : virtual public IInterpolatingApplicator
{
public:
  LinearInterpolator(T_Payload& target)
    : mTarget(target)
  {}

  void apply(time_t t,const INode& n0, const INode& n1) override
  {
    // we make an assumption that node is the default implementation provided by this library
    //assert(dynamic_cast<const Node<T_Payload>&>(n0));
    //assert(dynamic_cast<const Node<T_Payload>&>(n1));
    auto node0 = reinterpret_cast<const Node<const T_Payload>&>(n0);
    auto node1 = reinterpret_cast<const Node<const T_Payload>&>(n1);
    
    const auto v0 = node0.value();
    const time_t t0 = node0.time();
    const auto v1 = node1.value();
    const time_t t1 = node1.time();
    const float dt = (float)(t-t0)/(float)(t1-t0);
    mTarget = v0 + ((v1-v0)*dt);
  }

private:
  T_Payload& mTarget;
};

} // namespace Applicators
} // namespace Animator

#endif // _APPLICATOR_LINEARINTERPOLATOR_h