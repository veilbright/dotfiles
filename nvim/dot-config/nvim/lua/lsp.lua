vim.api.nvim_create_autocmd("LspAttach", {
	callback = function(args)
		local client = vim.lsp.get_client_by_id(args.data.client_id)
		if client == nil then
			return
		end
		if client.supports_method("textDocument/codeAction") then
			vim.keymap.set("n", "<leader>ca", vim.lsp.buf.code_action, { desc = "Code Action" })
		end
		if client.supports_method("textDocument/rename") then
			vim.keymap.set("n", "<leader>rn", vim.lsp.buf.rename, { desc = "Rename" })
		end
		if client.supports_method("textDocument/formatting") then
			vim.keymap.set("n", "<leader>cf", vim.lsp.buf.format, { desc = "Code Format" })
		end
		if client.supports_method("textDocument/definition") then
			vim.keymap.set("n", "gd", vim.lsp.buf.definition, { desc = "Go To Definition" })
		end
		if client.supports_method("textDocument/references") then
			vim.keymap.set("n", "<leader>rf", vim.lsp.buf.references, { desc = "List References" })
		end
		if client.supports_method("textDocument/hover") then
			vim.keymap.set("n", "gt", vim.lsp.buf.hover, { desc = "Show Information" })
		end
		if client.supports_method("textDocument/implementation") then
			vim.keymap.set("n", "gi", vim.lsp.buf.implementation, { desc = "Go To Implementation" })
		end
	end,
})
