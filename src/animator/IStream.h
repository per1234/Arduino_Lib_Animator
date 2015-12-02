/* IStream interface
 * Paul Wightmore 2015
 */
#ifndef _ISTREAM_h
#define _ISTREAM_h

using namespace std;

namespace Animator {

class INode;

class IStream
{
public:
  //! A list of animation nodes
  typedef ForwardLinkedList<const INode*> NodeList;
  
public:
  //! A unique name for the stream
  virtual const char* name();
  
  //! Get all nodes in the animation
  virtual const NodeList getNodes();
  
  //! Get all nodes within \p range
  virtual const NodeList getNodes(range_t range);
  
  //! Add a new node to the animation
  virtual void addNode(time_t time, const INode* node);
  
  //! Remove a node from the animation
  virtual void removeNode(time_t time, const INode* node);
  
  
};

} // namespace Animator

#endif // _ISTREAM_h