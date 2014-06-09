/*
 * Comm.h
 *
 *  Created on: 2014��6��4��
 *      Author: huangqi
 */

#ifndef COMM_H_
#define COMM_H_

namespace huang
{
namespace collaborator
{

enum functionlist
{
	LOGIN = 1001,
	LOGOUT,
	CHANGESTATUS
};

class Comm
{
public:
	Comm();
	virtual ~Comm();

public:
	static int LeasePort();
};

} /* namespace collaborator */
} /* namespace huang */

#endif /* COMM_H_ */
