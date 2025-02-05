return {
	"nvim-telescope/telescope-file-browser.nvim",
	dependencies = { "nvim-telescope/telescope.nvim", "nvim-lua/plenary.nvim" },
	init = function()
		vim.keymap.set("n", "<leader>tf", function()
			require("telescope").extensions.file_browser.file_browser()
		end, { desc = "Telescope File Browser" })
	end,
}
