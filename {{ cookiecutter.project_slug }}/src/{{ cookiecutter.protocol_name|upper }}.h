// Generated by binpac_quickstart

#ifndef ANALYZER_PROTOCOL_{{ name|upper }}_{{ name|upper }}_H
#define ANALYZER_PROTOCOL_{{ name|upper }}_{{ name|upper }}_H

#include "events.bif.h"

{% if tcp %}
#include "analyzer/protocol/tcp/TCP.h"
{% elif udp %}
#include "analyzer/protocol/udp/UDP.h"
{% endif %}
#include "{{ name|lower }}_pac.h"

namespace analyzer { namespace {{ name }} {

class {{ name|upper }}_Analyzer
{% if tcp %}
: public tcp::TCP_ApplicationAnalyzer {
{% elif udp %}
: public analyzer::Analyzer {
{% endif %}
public:
	{{ name|upper }}_Analyzer(Connection* conn);
	virtual ~{{ name|upper }}_Analyzer();

	// Overriden from Analyzer.
	virtual void Done();
	{% if tcp %}
	virtual void DeliverStream(int len, const u_char* data, bool orig);
	virtual void Undelivered(uint64 seq, int len, bool orig);

	// Overriden from tcp::TCP_ApplicationAnalyzer.
	virtual void EndpointEOF(bool is_orig);
	{% elif udp %}
	virtual void DeliverPacket(int len, const u_char* data, bool orig,
					uint64 seq, const IP_Hdr* ip, int caplen);
	{% endif %}

	static analyzer::Analyzer* InstantiateAnalyzer(Connection* conn)
		{ return new {{ name|upper }}_Analyzer(conn); }

protected:
	binpac::{{ name|upper }}::{{ name|upper }}_Conn* interp;
	{% if tcp %}
	bool had_gap;
	{% endif %}
};

} } // namespace analyzer::* 

#endif