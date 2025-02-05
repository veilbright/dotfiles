return {
	"nvim-telescope/telescope.nvim",
	branch = "0.1.x",
	dependencies = {
		"nvim-lua/plenary.nvim",
		{
			"nvim-telescope/telescope-fzf-native.nvim",
			build = "make",
		},
	},

	config = function()
		require("telescope").setup({
			extensions = {
				fzf = {
					fuzzy = true,
					override_generic_sorter = true,
					override_file_sorter = true,
					case_mode = "smart_case",
				},
				file_browser = {
					hijack_netrw = true,
				},
			},
		})
		require("telescope").load_extension("fzf")
		require("telescope").load_extension("file_browser")

		local builtin = require("telescope.builtin")
		vim.keymap.set("n", "<leader>tt", builtin.find_files, { desc = "Telescope Find Files" })
		vim.keymap.set("n", "<leader>tg", builtin.live_grep, { desc = "Telescope Live Grep" })
		vim.keymap.set("n", "<leader>tu", builtin.buffers, { desc = "Telescope Buffers" })
		vim.keymap.set("n", "<leader>th", builtin.help_tags, { desc = "Telescope Help Tags" })
	end,
}
