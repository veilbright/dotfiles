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
	end,
})
