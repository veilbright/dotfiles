return {
	"iamcco/markdown-preview.nvim",
	cmd = { "MarkdownPreviewToggle", "MarkdownPreview", "MarkdownPreviewStop" },
	build = function()
		require("lazy").load({ plugins = { "markdown-preview.nvim" } })
		vim.fn["mkdp#util#install"]()
	end,
	keys = {
		{
			"<leader>ms",
			ft = "markdown",
			"<cmd>MarkdownPreview<cr>",
			desc = "Markdown Preview",
		},
		{
			"<leader>mt",
			ft = "markdown",
			"<cmd>MarkdownPreviewStop<cr>",
			desc = "Markdown Preview Stop",
		},
	},
	config = function()
		vim.cmd([[do FileType]])
		vim.cmd('let g:mkdp_browser="/usr/bin/librewolf"')
	end,
}
