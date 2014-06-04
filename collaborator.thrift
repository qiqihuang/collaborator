namespace * huang.collaborator

enum ActionT {
  ADD = 1,
  DEL = 2,
  MOD = 3,
  CURSOR = 4
}

struct Action {
  1: ActionT actT,
  2: string data
}

enum OperationT {
  DIFF = 1,
  MATCH = 2,
  PATCH = 3
}

struct Operation {
  1: OperationT optT,
  2: string data
}

enum StatusT {
  NORMAL = 1,
  BUSY = 2,
  DISCONNECT = 3
}

struct UserInfo {
  1: string userId,
  2: string sessionId,
  3: StatusT status,
}

service collaborate {

  string action(1:UserInfo user, 2:string cmd, 3:string params),
  
  oneway void callback(1:UserInfo user, 2:string event, 3:string contents),
  
  void ping(),
  
}


