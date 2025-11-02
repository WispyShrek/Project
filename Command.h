#ifndef COMMAND_H
#define COMMAND_H

/** @class Command 
 * @brief Abstract base class for commands in the Command Pattern.
 * 
 * This class defines the interface for executing commands.
 * Derived classes must implement the execute() method.
 */


class Command {
 
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
};

#endif
