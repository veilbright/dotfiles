return {
	"miikanissi/modus-themes.nvim",
	priority = 1000,
	opts = {
		line_nr_column_background = false,
	},
	init = function()
		vim.cmd.colorscheme("modus")
	end,
}
