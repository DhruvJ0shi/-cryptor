#pragma once
#ifndef CIPHER_INCLUDED_H
#define CIPHER_INCLUDED_H

#include <string>
#include "Message.h"

namespace Cryptor
{
	enum class Mode
	{
		ENCRYPT,
		DECRYPT
	};
	class Cipher
	{
	public:
		Cipher( int key = 0, Mode mode = Mode::ENCRYPT ):
			m_key( key ),
			m_mode( mode ),
			m_oldMsg( Cryptor::Message::Message() ),
			m_newMsg( Cryptor::Message::Message() ) {}

		inline void SetKey( int key ) { m_key = key; }
		int GetKey() { return m_key; }

		inline void SetMode( const Mode& mode ) { m_mode = mode; }
		const inline Mode GetMode() { return m_mode; }
		
		inline Cryptor::Message* Message()		{ return &m_oldMsg; }
		inline Cryptor::Message* NewMessage()	{ return &m_newMsg; }

		/*
		virtual void Encrypt() {}
		virtual void Decrypt() {}
		*/
	private:
		int m_key;
		Mode m_mode;
		Cryptor::Message m_oldMsg, m_newMsg;
	};
}

#endif