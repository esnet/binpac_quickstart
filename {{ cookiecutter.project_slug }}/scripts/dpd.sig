# Generated by binpac_quickstart

signature dpd_{{ name|lower }} {
	{% if tcp %}
	ip-proto == tcp
	{% elif udp %}
	ip-proto == udp
	{% endif %}

	# ## TODO: Define the payload. When Bro sees this regex, on
	# ## any port, it will enable your analyzer on that
	# ## connection.
	# ## payload /^{{ name|upper }}/

	enable "{{ name|lower }}"
}