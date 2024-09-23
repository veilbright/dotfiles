return {
  'lervag/vimtex',
  lazy = false, -- required per github

  init = function()
    vim.g.vimtex_view_general_viewer = 'sumatrapdf'
  end,
}
