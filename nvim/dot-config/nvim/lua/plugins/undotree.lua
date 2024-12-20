return {
	"mbbill/undotree",
	init = function()
		vim.keymap.set("n", "<leader>tu", vim.cmd.UndotreeToggle)
	end,
}
