return {
	"folke/todo-comments.nvim",
	dependencies = {
		"nvim-lua/plenary.nvim",
		"nvim-telescope/telescope.nvim",
	},
	opts = {},
	init = function()
		vim.keymap.set("n", "<leader>td", function()
			vim.cmd("TodoTelescope")
		end, { desc = "Open Todo Comments in Telescope" })
	end,
}
