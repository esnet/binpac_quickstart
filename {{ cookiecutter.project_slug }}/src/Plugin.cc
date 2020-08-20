// Generated by binpac_quickstart

#include "plugin/Plugin.h"

#include "{{ name|upper }}.h"

namespace plugin {
namespace Bro_{{ name|upper }} {

class Plugin : public plugin::Plugin {
public:
	plugin::Configuration Configure()
		{
		AddComponent(new ::analyzer::Component("{{ name|upper }}",
		             ::analyzer::{{ name }}::{{ name|upper }}_Analyzer::InstantiateAnalyzer));

		plugin::Configuration config;
		config.name = "Bro::{{ name|upper }}";
		config.description = "{{ desc }} analyzer";
		return config;
		}
} plugin;

}
}