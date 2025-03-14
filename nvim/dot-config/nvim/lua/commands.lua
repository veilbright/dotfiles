vim.api.nvim_create_user_command("DiagnosticToggle", function()
	local config = vim.diagnostic.config
	vim.diagnostic.config({
		virtual_text = not config().virtual_text,
		underline = not config().underline,
	})
end, { desc = "Toggle diagnostic" })
