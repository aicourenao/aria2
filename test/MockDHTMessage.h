#ifndef _D_MOCK_DHT_MESSAGE_H_
#define _D_MOCK_DHT_MESSAGE_H_

#include "DHTMessage.h"

#include <deque>

#include "DHTNode.h"
#include "Peer.h"

namespace aria2 {

class MockDHTMessage:public DHTMessage {
public:
  bool _isReply;

  std::string _messageType;

  std::vector<SharedHandle<DHTNode> > _nodes;

  std::vector<SharedHandle<Peer> > _peers;

  std::string _token;
public:
  MockDHTMessage(const SharedHandle<DHTNode>& localNode,
                 const SharedHandle<DHTNode>& remoteNode,
                 const std::string& messageType = "mock",
                 const std::string& transactionID = ""):
    DHTMessage(localNode, remoteNode, transactionID), _isReply(false), _messageType(messageType) {}
  
  virtual ~MockDHTMessage() {}

  virtual void doReceivedAction() {}

  virtual bool send() { return true; }

  virtual bool isReply() const { return _isReply; }

  void setReply(bool f) { _isReply = f; }

  virtual const std::string& getMessageType() const { return _messageType; }

  virtual std::string toString() const { return "MockDHTMessage"; }
};

} // namespace aria2

#endif // _D_MOCK_DHT_MESSAGE_H_
