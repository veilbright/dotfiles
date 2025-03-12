return {
	"nvimtools/none-ls.nvim",

	config = function()
		local null_ls = require("null-ls")
		vim.keymap.set("n", "<leader>f", function()
			vim.lsp.buf.format({ async = false })
		end, { desc = "Format" })

		local augroup = vim.api.nvim_create_augroup("LspFormatting", {})
		null_ls.setup({
			sources = {
				null_ls.builtins.formatting.stylua, -- lua
				null_ls.builtins.formatting.clang_format, -- C
				null_ls.builtins.formatting.gersemi, -- CMake
				null_ls.builtins.formatting.black, -- python
				null_ls.builtins.formatting.phpcsfixer, -- PHP
			},
			-- format on save
			on_attach = function(client, bufnr)
				if client.supports_method("textDocument/formatting") then
					vim.api.nvim_clear_autocmds({ group = augroup, buffer = bufnr })
					vim.api.nvim_create_autocmd("BufWritePre", {
						group = augroup,
						buffer = bufnr,
						callback = function()
							vim.lsp.buf.format({ async = false })
						end,
					})
				end
			end,
		})
	end,
}
