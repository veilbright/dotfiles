return {
	"neovim/nvim-lspconfig",
	dependencies = {
		"williamboman/mason.nvim",
		"williamboman/mason-lspconfig.nvim",
		"saghen/blink.cmp",
	},
	opts = {
		servers = {
			lua_ls = {
				settings = {
					Lua = {
						runtime = {
							version = _VERSION,
						},
						workspace = {
							library = {
								vim.env.VIMRUNTIME,
							},
						},
					},
				},
			},
			clangd = {},
			cmake = {},
			html = {
				settings = {
					html = {
						format = {
							templating = true,
						},
						hover = {
							documentation = true,
							references = true,
						},
						validate = {
							scripts = true,
							styles = true,
						},
					},
				},
				filetypes = {
					"html",
					"templ",
					"tpl",
				},
				snippet = true,
			},
			cssls = {
				snippet = true,
			},
			pyright = {},
			sqlls = {},
			typos_lsp = {},
			phpactor = {},
			gopls = {},
			eslint = {},
			ts_ls = {},
			omnisharp = {},
			arduino_language_server = {},
		},
	},
	config = function(_, opts)
		local lspconfig = require("lspconfig")
		for server, config in pairs(opts.servers) do
			config.capabilities = require("blink.cmp").get_lsp_capabilities(config.capabilities)
			if config.snippet == true then
				config.capabilities = require("blink.cmp").get_lsp_capabilities(config.capabilities)
			end
			lspconfig[server].setup(config)
		end
	end,
}
