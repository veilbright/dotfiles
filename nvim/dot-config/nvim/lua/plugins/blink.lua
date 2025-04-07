return {
	"saghen/blink.cmp",
	version = "*",

	opts = {
		keymap = { preset = "default" },
		appearance = {
			use_nvim_cmp_as_default = true,
			nerd_font_variant = "mono",
		},
		sources = {
			default = { "lsp", "path", "snippets", "buffer", "cmdline" },
		},
		cmdline = {
			enabled = true,
			completion = {
				menu = { auto_show = true },
				ghost_text = { enabled = true },
			},
		},
		signature = { enabled = true },
		fuzzy = { implementation = "prefer_rust_with_warning" },
	},
	opts_extend = { "sources.default" },
}
