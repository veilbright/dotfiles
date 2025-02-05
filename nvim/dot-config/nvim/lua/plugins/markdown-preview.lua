return {
	"iamcco/markdown-preview.nvim",
	cmd = { "MarkdownPreviewToggle", "MarkdownPreview", "MarkdownPreviewStop" },
	ft = { "markdown", "PlantUML" },
	build = function()
		require("lazy").load({ plugins = { "markdown-preview.nvim" } })
		vim.fn["mkdp#util#install"]()
	end,
	keys = {
		{
			"<leader>mp",
			"<cmd>MarkdownPreview<cr>",
			desc = "Markdown Preview",
		},
		{
			"<leader>mt",
			"<cmd>MarkdownPreviewStop<cr>",
			desc = "Markdown Preview Stop",
		},
	},
	config = function()
		vim.cmd([[do FileType]])
		vim.cmd('let g:mkdp_browser="/usr/bin/librewolf"')
		vim.cmd("let g:mkdp_filetypes=['markdown', 'PlantUML']")
	end,
}
