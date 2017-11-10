

/* Copyright ChenDong(Wilbur), email <baisaichen@live.com>. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef LIGHTINK_LOG_LOGCHANNELOSTREAM_H_
#define LIGHTINK_LOG_LOGCHANNELOSTREAM_H_

#include <ostream>
#include "Log/channel/LogChannelMT.h"

namespace LightInk
{
	template <typename M>
	class LIGHTINK_TEMPLATE_DECL LogChannelOstream : public LogChannelMT<M>
	{
	public:
		LogChannelOstream(std::ostream & os);
		virtual ~LogChannelOstream();

	protected:
		virtual RuntimeError do_log(const LogItem & item);
		virtual RuntimeError do_flush();

	protected:
		std::ostream & m_ostream;

	LIGHTINK_DISABLE_COPY(LogChannelOstream)
	};
	///////////////////////////////////////////////////////////////////////
	//inline method
	//////////////////////////////////////////////////////////////////////
	template <typename M>
	LogChannelOstream<M>::LogChannelOstream(std::ostream & os) : m_ostream(os) {  }

	template <typename M>
	LogChannelOstream<M>::~LogChannelOstream() { flush(); }

	template <typename M>
	RuntimeError LogChannelOstream<M>::do_log(const LogItem & item)
	{
		m_ostream.write(item.m_format.data(), item.m_format.size());
		return RE_Success;
	}

	template <typename M>
	RuntimeError LogChannelOstream<M>::do_flush()
	{
		m_ostream.flush();
		return RE_Success;
	}
}

#endif