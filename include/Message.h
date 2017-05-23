#pragma once
#ifndef MESSAGE_INCLUDED_H
#define MESSAGE_INCLUDED_H

#include <string>

namespace Cryptor
{
	class Message
	{
	public:
		Message() { m_msg = std::string(); }

		inline void SetMsg( const std::string& msg )
		{
			m_msg = msg;
			m_msgLength = m_msg.size();
		}
		const inline std::string GetMsg() { return m_msg; }

		const inline void SetMsgLength( int length ) { m_msgLength = length; }
		int GetMsgLength() { return m_msgLength; }
	private:
		int m_msgLength;
		std::string m_msg;
	};
}

#endif