/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef collaborator_TYPES_H
#define collaborator_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace huang { namespace collaborator {

struct ActionT {
  enum type {
    ADD = 1,
    DEL = 2,
    MOD = 3,
    CURSOR = 4
  };
};

extern const std::map<int, const char*> _ActionT_VALUES_TO_NAMES;

struct OperationT {
  enum type {
    DIFF = 1,
    MATCH = 2,
    PATCH = 3
  };
};

extern const std::map<int, const char*> _OperationT_VALUES_TO_NAMES;

struct StatusT {
  enum type {
    NORMAL = 1,
    BUSY = 2,
    DISCONNECT = 3
  };
};

extern const std::map<int, const char*> _StatusT_VALUES_TO_NAMES;

typedef struct _Action__isset {
  _Action__isset() : actT(false), data(false) {}
  bool actT;
  bool data;
} _Action__isset;

class Action {
 public:

  static const char* ascii_fingerprint; // = "19B5240589E680301A7E32DF3971EFBE";
  static const uint8_t binary_fingerprint[16]; // = {0x19,0xB5,0x24,0x05,0x89,0xE6,0x80,0x30,0x1A,0x7E,0x32,0xDF,0x39,0x71,0xEF,0xBE};

  Action() : actT((ActionT::type)0), data() {
  }

  virtual ~Action() throw() {}

  ActionT::type actT;
  std::string data;

  _Action__isset __isset;

  void __set_actT(const ActionT::type val) {
    actT = val;
  }

  void __set_data(const std::string& val) {
    data = val;
  }

  bool operator == (const Action & rhs) const
  {
    if (!(actT == rhs.actT))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const Action &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Action & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Action &a, Action &b);

typedef struct _Operation__isset {
  _Operation__isset() : optT(false), data(false) {}
  bool optT;
  bool data;
} _Operation__isset;

class Operation {
 public:

  static const char* ascii_fingerprint; // = "19B5240589E680301A7E32DF3971EFBE";
  static const uint8_t binary_fingerprint[16]; // = {0x19,0xB5,0x24,0x05,0x89,0xE6,0x80,0x30,0x1A,0x7E,0x32,0xDF,0x39,0x71,0xEF,0xBE};

  Operation() : optT((OperationT::type)0), data() {
  }

  virtual ~Operation() throw() {}

  OperationT::type optT;
  std::string data;

  _Operation__isset __isset;

  void __set_optT(const OperationT::type val) {
    optT = val;
  }

  void __set_data(const std::string& val) {
    data = val;
  }

  bool operator == (const Operation & rhs) const
  {
    if (!(optT == rhs.optT))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const Operation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Operation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Operation &a, Operation &b);

typedef struct _UserInfo__isset {
  _UserInfo__isset() : userId(false), sessionId(false), info(false) {}
  bool userId;
  bool sessionId;
  bool info;
} _UserInfo__isset;

class UserInfo {
 public:

  static const char* ascii_fingerprint; // = "AB879940BD15B6B25691265F7384B271";
  static const uint8_t binary_fingerprint[16]; // = {0xAB,0x87,0x99,0x40,0xBD,0x15,0xB6,0xB2,0x56,0x91,0x26,0x5F,0x73,0x84,0xB2,0x71};

  UserInfo() : userId(), sessionId(), info() {
  }

  virtual ~UserInfo() throw() {}

  std::string userId;
  std::string sessionId;
  std::string info;

  _UserInfo__isset __isset;

  void __set_userId(const std::string& val) {
    userId = val;
  }

  void __set_sessionId(const std::string& val) {
    sessionId = val;
  }

  void __set_info(const std::string& val) {
    info = val;
  }

  bool operator == (const UserInfo & rhs) const
  {
    if (!(userId == rhs.userId))
      return false;
    if (!(sessionId == rhs.sessionId))
      return false;
    if (!(info == rhs.info))
      return false;
    return true;
  }
  bool operator != (const UserInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(UserInfo &a, UserInfo &b);

}} // namespace

#endif
